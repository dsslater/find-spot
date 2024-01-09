load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "get_neighborhood_handler",
    srcs = ["get_neighborhood_handler.cc"],
    hdrs = ["get_neighborhood_handler.h"],
    deps = [
        "//neighborhood_finder/protos:neighborhood_cc_grpc",
        "@com_github_google_glog//:glog",
        "@com_github_grpc_grpc//:grpc++",
    ],
)

cc_library(
    name = "neighborhood_finder_service",
    srcs = ["neighborhood_finder_service.cc"],
    hdrs = ["neighborhood_finder_service.h"],
    deps = [
        ":get_neighborhood_handler",
        "//neighborhood_finder/protos:neighborhood_cc_grpc",
        "@com_github_google_glog//:glog",
        "@com_github_grpc_grpc//:grpc++",
    ],
)

cc_binary(
    name = "neighborhood_finder_service_main",
    srcs = ["neighborhood_finder_service_main.cc"],
    defines = ["BAZEL_BUILD"],
    deps = [
        ":get_neighborhood_handler",
        ":neighborhood_finder_service",
        "//neighborhood_finder/protos:neighborhood_cc_grpc",
        "@com_github_gflags_gflags//:gflags",
        "@com_github_grpc_grpc//:grpc++",
        "@com_github_grpc_grpc//:grpc++_reflection",
    ],
)
