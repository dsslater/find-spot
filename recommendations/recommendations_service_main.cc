#include <iostream>
#include <memory>
#include <string>

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <grpcpp/grpcpp.h>

#include "recommendations/recommendations_service.h"
#include "recommendations/protos/recommendations.grpc.pb.h"

using ::grpc::Channel;
using ::grpc::ClientContext;
using ::grpc::InsecureServerCredentials;
using ::grpc::Server;
using ::grpc::ServerBuilder;
using ::recommendations::CreateRecommendationsService;


void RunServer(std::shared_ptr<grpc::Channel> neighborhood_channel) {
  std::string address = "0.0.0.0";
  std::string port = "50051";
  std::string server_address = address + ":" + port;
  auto service = CreateRecommendationsService(neighborhood_channel);

  ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, InsecureServerCredentials());
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(service.get());
  // Finally assemble the server.
  std::unique_ptr<Server> server(builder.BuildAndStart());
  LOG(INFO) << "Server listening on " << server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

int main(int argc, char **argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  std::shared_ptr<grpc::Channel> neighborhood_channel = grpc::CreateChannel(
      "localhost:50052", grpc::InsecureChannelCredentials());

  RunServer(neighborhood_channel);

  return 0;
}