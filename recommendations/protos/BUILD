package(default_visibility = ["//visibility:public"])

load("@rules_proto//proto:defs.bzl", "proto_library")
load("@com_github_grpc_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")

proto_library(
    name = "recommendations_proto",
    srcs = [
        "recommendations.proto",
    ],
    deps = [
        "//protos:participants_proto",
    ],
)

cc_proto_library(
    name = "recommendations_cc_proto",
    deps = [":recommendations_proto"],
)

cc_grpc_library(
    name = "recommendations_cc_grpc",
    srcs = [":recommendations_proto"],
    grpc_only = True,
    deps = [":recommendations_cc_proto"],
)
