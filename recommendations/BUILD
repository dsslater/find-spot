load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "get_recommendations_handler",
    srcs = ["get_recommendations_handler.cc"],
    hdrs = ["get_recommendations_handler.h"],
    deps = [
        "//recommendations/protos:recommendations_cc_grpc",
        "@com_github_google_glog//:glog",
        "@com_github_grpc_grpc//:grpc++",
    ],
)

cc_binary(
    name = "recommendation_service",
    srcs = ["recommendations_main.cc"],
    defines = ["BAZEL_BUILD"],
    deps = [
        ":get_recommendations_handler",
        "//recommendations/protos:recommendations_cc_grpc",
        "@com_github_gflags_gflags//:gflags",
        "@com_github_grpc_grpc//:grpc++",
        "@com_github_grpc_grpc//:grpc++_reflection",
    ],
)
