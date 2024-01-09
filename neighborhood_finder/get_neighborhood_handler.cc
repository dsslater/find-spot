#include "neighborhood_finder/get_neighborhood_handler.h"
#include "neighborhood_finder/protos/neighborhood.grpc.pb.h"

#include <glog/logging.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/support/status.h>

namespace neighborhood_finder {

using ::grpc::ServerContext;
using ::grpc::Status;
using ::neighborhood_finder::GetNeighborhoodRequest;
using ::neighborhood_finder::GetNeighborhoodResponse;

Status HandleGetNeighborhood(ServerContext *context,
                                const GetNeighborhoodRequest *request,
                                GetNeighborhoodResponse *reply) {
  LOG(INFO) << "Calling HandleGetNeighborhood";
  reply->set_neighborhood("Upper West Side");
  return Status::OK;
}

} // namespace neighborhood_finder