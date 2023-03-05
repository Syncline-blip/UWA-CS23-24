def dinner_calculator(meal_cost, drinks_cost):
    """Calculates dinner cost with included discount and gst"""
    drink_discount = 0.7
    goodservice_tax = 1.15
    drinks_cost = drinks_cost * drink_discount
    total_cost = (drinks_cost + meal_cost) * goodservice_tax
    return total_cost



total_cost = dinner_calculator(10,0)
print(total_cost) 

total_cost = dinner_calculator(12,4)
print(total_cost)