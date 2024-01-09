#include "neighborhood_finder/neighborhood_finder_service.h"

#include <glog/logging.h>
#include <grpcpp/grpcpp.h>

#include "neighborhood_finder/neighborhood_finder_service.h"
#include "neighborhood_finder/protos/neighborhood.grpc.pb.h"
#include "recommendations/get_recommendations_handler.h"
#include "recommendations/protos/recommendations.grpc.pb.h"

namespace recommendations {
namespace {

using ::grpc::Channel;
using ::grpc::ClientContext;
using ::grpc::ServerContext;
using ::grpc::Status;
using ::neighborhood_finder::NeighborhoodFinderClient;
using ::recommendations::GetRecommendationsRequest;
using ::recommendations::GetRecommendationsResponse;
using ::recommendations::Recommendations;

class RecommendationsServiceImpl final : public Recommendations::Service {
public:
  RecommendationsServiceImpl(
      std::shared_ptr<grpc::Channel> neighborhood_channel)
      : client_(NeighborhoodFinderClient::Create(neighborhood_channel)) {}

  ~RecommendationsServiceImpl() override = default;

  Status GetRecommendations(ServerContext *context,
                            const GetRecommendationsRequest *request,
                            GetRecommendationsResponse *reply) override {
    client_.GetNeighborhood();
    return HandleGetRecommendations(context, request, reply);
  }

private:
  NeighborhoodFinderClient client_;
};

} // namespace

std::unique_ptr<grpc::Service> CreateRecommendationsService(
    std::shared_ptr<grpc::Channel> neighborhood_channel) {
  return std::make_unique<RecommendationsServiceImpl>(neighborhood_channel);
}

} // namespace recommendations