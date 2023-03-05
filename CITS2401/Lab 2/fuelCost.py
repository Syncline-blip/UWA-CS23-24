def trip_cost(price, distance, economy):
    """ Calculate fuel cost """
    fuel = distance / (100/economy) * price
    return fuel

print(round(trip_cost(1.3, 10, 5), 2))
print(round(trip_cost(1.68, 27, 7.7), 2))