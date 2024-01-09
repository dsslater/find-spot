#ifndef RECCOMENDATIONS_SERVER_HANDLERS_GET_RECOMMENDATIONS_HANDLER_H_
#define RECCOMENDATIONS_SERVER_HANDLERS_GET_RECOMMENDATIONS_HANDLER_H_

#include <grpcpp/grpcpp.h>

#include "recommendations/protos/recommendations.grpc.pb.h"

namespace recommendations {

grpc::Status HandleGetRecommendations(grpc::ServerContext *context,
                            const GetRecommendationsRequest *request,
                            GetRecommendationsResponse *reply);

}  // namespace recommendations

#endif  // RECOMMENDATIONS_SERVER_HANDLERS_GET_RECOMMENDATIONS_HANDLER_H_