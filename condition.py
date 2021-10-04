# Filter out columns of our interest
df_1 = df.loc[:, ["Quantity", "Unit price"]]
 
# We have already binned the quantity data into 0 and 1's for counting.
# So we don't need any pre-processing
 
# Group the data
groupby = df_1.groupby("Quantity", axis=0)
 
# Apply the function(here mean)
groupby.mean()
