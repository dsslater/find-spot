#include "recommendations/get_recommendations_handler.h"
#include "recommendations/protos/recommendations.grpc.pb.h"

#include <glog/logging.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/support/status.h>

namespace recommendations {

using ::grpc::ServerContext;
using ::grpc::Status;

Status HandleGetRecommendations(ServerContext *context,
                                const GetRecommendationsRequest *request,
                                GetRecommendationsResponse *reply) {
  LOG(INFO) << "Calling HandleGetRecommendations";
  return Status::OK;
}

} // namespace recommendations