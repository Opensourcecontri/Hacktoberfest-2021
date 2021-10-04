# Query the database for Quantity greater than 3
df_g = df.query('Quantity > 3')
 
# Filter out labels of interest
df_g = df_g.filter(['City', 'Unit price'])
 
# Group the value according to a condition
df_g.groupby('City').mean()
