'''Chef has started Home Delivery scheme in one of his restaurants. As the scheme is new , Chef appoints only one employee to deliver food to various locations. The delivery boy who has been appointed is an absent-minded chap. He always forgets to fill fuel in his delivery scooter. So what he does is that whenever Chef sends him for delivery, he goes to the gas station from the restaurant first. He gets his tank filled and then he heads towards his destination. He will do this every single time irrespective of the destination. The delivery boy tries his best to be on time. And to do this, he will choose those paths(from restaurant to gas station AND gas station to destinaion) which cost him the least amount of time. Your task is to tell the Chef how much time can the delivery boy save if he had enough fuel in his scooter i.e. if he went to the destination directly without stopping for fuel (taking the path which costs him least amount of time).

The city has N streets numbered from 0 to N-1. The restaurant is on street number S, the gas station is on street number G and the food has to be delivered to street D . Note that S, G and D need not be distinct.

'''
def delivery_time_and_savings(N, T, M, scenarios):
    # Floyd-Warshall algorithm to find shortest paths
    for k in range(N):
        for i in range(N):
            for j in range(N):
                T[i][j] = min(T[i][j], T[i][k] + T[k][j])

    # Process each scenario
    for scenario in scenarios:
        S, G, D = scenario
        direct_time = T[S][D]  # Time if he went directly from S to D
        via_gas_station_time = T[S][G] + T[G][D]  # Time if he stops at gas station
        time_saved = via_gas_station_time - direct_time
        print(f"{via_gas_station_time} {time_saved}")

# Read input
N = int(input())
T = [list(map(int, input().split())) for _ in range(N)]
M = int(input())
scenarios = [list(map(int, input().split())) for _ in range(M)]

# Output results
delivery_time_and_savings(N, T, M, scenarios)
