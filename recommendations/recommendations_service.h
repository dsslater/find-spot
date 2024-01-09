#ifndef  RECOMMENDATIONS_RECOMMENDATIONS_SERVICE_H_
#define  RECOMMENDATIONS_RECOMMENDATIONS_SERVICE_H_

#include <grpcpp/grpcpp.h>

namespace recommendations {

std::unique_ptr<grpc::Service> CreateRecommendationsService(std::shared_ptr<grpc::Channel> neighborhood_channel);


}  // namespace recommendations


#endif  // RECOMMENDATIONS_RECOMMENDATIONS_SERVICE_H