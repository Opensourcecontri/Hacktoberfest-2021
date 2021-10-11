temperature = input("Input the temperature (Example -  12F, 98C ...): ")
temp_value = int(temperature[:-1])
temp_type = temperature[-1]

if temp_type.upper() == "C":
  converted_temp_value = int(round((9 * temp_value) / 5 + 32))
  converted_temp_type = "F"
elif temp_type.upper() == "F":
  converted_temp_value = int(round((temp_value - 32) * 5 / 9))
  converted_temp_type = "C"
else:
  print("Invalid temperature type.")
  quit()
  
print("The temperature in", converted_temp_type, "is", converted_temp_value, "degrees.")