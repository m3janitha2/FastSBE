"""Bazel rule for generating C++ SBE codecs with FastSBE.

    load("@fastsbe//:defs.bzl", "fastsbe_cc_library")

    fastsbe_cc_library(
        name = "cme_sbe",
        schema = "cme-mdp3-v13.xml",
        namespace = "cme",
    )

    cc_binary(name = "app", srcs = ["app.cpp"], deps = [":cme_sbe"])

The generator emits a header per message/composite/enum/set; the exact set
depends on the schema, so the rule captures the whole output as a single
directory (tree artifact) and exposes it as a C++ include path. Consumers then
`#include "MessageName.h"` as usual.
"""

def _fastsbe_generate_impl(ctx):
    # One directory output for the variable set of generated headers.
    out_dir = ctx.actions.declare_directory(ctx.label.name)

    # The generator writes a log to its first argument; keep it out of the
    # header directory (and in an existing dir, since logging is set up before
    # the output folder is created).
    log_file = ctx.actions.declare_file(ctx.label.name + ".log")

    args = ctx.actions.args()
    args.add(log_file.path)
    args.add(ctx.file.schema.path)
    args.add(out_dir.path)
    if ctx.attr.namespace:
        args.add(ctx.attr.namespace)

    ctx.actions.run(
        executable = ctx.executable._generator,
        arguments = [args],
        inputs = [ctx.file.schema],
        outputs = [out_dir, log_file],
        mnemonic = "FastSBEGenerate",
        progress_message = "Generating SBE codec for %s" % ctx.label,
    )

    # Expose the generated directory as a C++ include path + headers.
    cc_ctx = cc_common.create_compilation_context(
        headers = depset([out_dir]),
        includes = depset([out_dir.path]),
    )
    return [
        DefaultInfo(files = depset([out_dir])),
        CcInfo(compilation_context = cc_ctx),
    ]

_fastsbe_generate = rule(
    implementation = _fastsbe_generate_impl,
    attrs = {
        "schema": attr.label(
            allow_single_file = [".xml"],
            mandatory = True,
            doc = "The SBE schema XML.",
        ),
        "namespace": attr.string(
            doc = "Optional C++ namespace override for the generated code.",
        ),
        "_generator": attr.label(
            default = Label("//:fastsbe"),
            executable = True,
            cfg = "exec",
        ),
    },
)

def fastsbe_cc_library(name, schema, namespace = "", visibility = None, **kwargs):
    """Generate SBE codecs from `schema` and wrap them in a cc_library."""
    _fastsbe_generate(
        name = name + ".gen",
        schema = schema,
        namespace = namespace,
    )
    native.cc_library(
        name = name,
        deps = [name + ".gen"],
        visibility = visibility,
        **kwargs
    )
