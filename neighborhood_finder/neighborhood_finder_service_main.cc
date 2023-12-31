#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include <glog/logging.h>
#include <gflags/gflags.h>

#include "neighborhood_finder/neighborhood_finder_service.h"
#include "neighborhood_finder/protos/neighborhood.grpc.pb.h"

using ::grpc::InsecureServerCredentials;
using ::grpc::Server;
using ::grpc::ServerBuilder;
using ::grpc::ServerContext;
using ::grpc::Status;
using ::neighborhood_finder::CreateNeighborhoodFinderService;



void RunServer() {
  std::string address = "0.0.0.0";
  std::string port = "50052";
  std::string server_address = address + ":" + port;
  std::unique_ptr<grpc::Service> service = CreateNeighborhoodFinderService();

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

  RunServer();

  return 0;
}