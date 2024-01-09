#include "neighborhood_finder/neighborhood_finder_service.h"

#include <glog/logging.h>
#include <grpcpp/grpcpp.h>

#include "neighborhood_finder/get_neighborhood_handler.h"
#include "neighborhood_finder/protos/neighborhood.grpc.pb.h"

namespace neighborhood_finder {
namespace {

using ::grpc::Channel;
using ::grpc::ClientContext;
using ::grpc::ServerContext;
using ::grpc::Status;
using ::neighborhood_finder::GetNeighborhoodRequest;
using ::neighborhood_finder::GetNeighborhoodResponse;

class NeighborhoodFinderServiceImpl final : public NeighborhoodFinder::Service {
  Status GetNeighborhood(ServerContext *context,
                         const GetNeighborhoodRequest *request,
                         GetNeighborhoodResponse *reply) override {
    return neighborhood_finder::HandleGetNeighborhood(context, request, reply);
  }
};

} // namespace

std::unique_ptr<grpc::Service> CreateNeighborhoodFinderService() {
  return std::make_unique<NeighborhoodFinderServiceImpl>();
}

NeighborhoodFinderClient::NeighborhoodFinderClient(std::shared_ptr<Channel> channel)
    : stub_(NeighborhoodFinder::NewStub(channel)) {}

void NeighborhoodFinderClient::GetNeighborhood() {
  ClientContext context;

  GetNeighborhoodRequest request;

  GetNeighborhoodResponse response;
  Status status = stub_->GetNeighborhood(&context, request, &response);

  if (!status.ok()) {
    std::cout << "GetNeighborhood rpc failed." << std::endl;
    return;
  }

  LOG(INFO) << "Neighborhood: " << response.neighborhood();
}

NeighborhoodFinderClient
NeighborhoodFinderClient::Create(std::shared_ptr<Channel> channel) {
  return NeighborhoodFinderClient(channel);
}

} // namespace neighborhood_finder