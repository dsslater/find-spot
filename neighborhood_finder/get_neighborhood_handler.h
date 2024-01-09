#ifndef NEIGBHORHOOD_SERVER_HANDLERS_GET_NEIGBHORHOOD_HANDLER_H_
#define NEIGBHORHOOD_SERVER_HANDLERS_GET_NEIGBHORHOOD_HANDLER_H_

#include <grpcpp/grpcpp.h>

#include "neighborhood_finder/protos/neighborhood.grpc.pb.h"

namespace neighborhood_finder {

grpc::Status HandleGetNeighborhood(grpc::ServerContext *context,
                            const neighborhood_finder::GetNeighborhoodRequest *request,
                            neighborhood_finder::GetNeighborhoodResponse *reply);

}  // namespace neighborhood_finder

#endif  // NEIGBHORHOOD_SERVER_HANDLERS_GET_NEIGBHORHOOD_HANDLER_H_