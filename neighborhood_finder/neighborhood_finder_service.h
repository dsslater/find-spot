#ifndef NEIGHBORHOOD_FINDER_NEIGHBORHOOD_FINDER_SERVICE_H_
#define NEIGHBORHOOD_FINDER_NEIGHBORHOOD_FINDER_SERVICE_H_

#include <grpcpp/grpcpp.h>

#include "neighborhood_finder/protos/neighborhood.grpc.pb.h"

namespace neighborhood_finder {

std::unique_ptr<grpc::Service> CreateNeighborhoodFinderService();

class NeighborhoodFinderClient {
public:
  void GetNeighborhood();

  static NeighborhoodFinderClient Create(std::shared_ptr<grpc::Channel> channel);

private:
  NeighborhoodFinderClient(std::shared_ptr<grpc::Channel> channel);

  std::unique_ptr<NeighborhoodFinder::Stub> stub_;
};

} // namespace neighborhood_finder

#endif // NEIGHBORHOOD_FINDER_NEIGHBORHOOD_FINDER_SERVICE_H