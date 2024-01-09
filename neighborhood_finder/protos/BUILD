package(default_visibility = ["//visibility:public"])

load("@rules_proto//proto:defs.bzl", "proto_library")
load("@com_github_grpc_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")

proto_library(
    name = "neighborhood_proto",
    srcs = ["neighborhood.proto"],
    deps = ["//protos:participants_proto"],
)

cc_proto_library(
    name = "neighborhood_cc_proto",
    deps = [":neighborhood_proto"],
)

cc_grpc_library(
    name = "neighborhood_cc_grpc",
    srcs = [":neighborhood_proto"],
    grpc_only = True,
    deps = [":neighborhood_cc_proto"],
)
