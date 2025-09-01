# Load required libraries
library(forecast)
library(ggplot2)
library(readr)

# Read the dataset
drug_sales <- read.csv("AusAntidiabeticDrug.csv")

# Check column names (you already verified: "ds", "y")
print(names(drug_sales))

# Convert 'ds' to Date format (if not already)
drug_sales$ds <- as.Date(drug_sales$ds)

# Create time series object (monthly data starting Jan 1991)
ts_data <- ts(drug_sales$y, start = c(1991, 1), frequency = 12)

# Fit Holt-Winters model
model <- HoltWinters(ts_data)

# Forecast the next 24 months
forecast_data <- forecast(model, h = 24)

# Plot the forecast

plot(forecast_data,
     main = "Monthly Antidiabetic Drug Sales Forecast",
     xlab = "Time",
     ylab = "Sales ($ Millions)",
     col.main = "darkblue",
     col.lab = "black")

#optional plot
decomposed <- decompose(ts_data)
plot(decomposed)


#Python code to forecast monthly antidiabetic drug sales using Holt-Winters method
 # Load libraries
# import pandas as pd
# import matplotlib.pyplot as plt
# from statsmodels.tsa.holtwinters import ExponentialSmoothing

# # Load the dataset
# df = pd.read_csv("AustraliaDrugSales.csv", parse_dates=['date'])
# df.set_index('date', inplace=True)
# df.index.freq = 'MS'  # MS = Month Start


# # Build and fit the model
# model = ExponentialSmoothing(
#     df['value'],
#     trend='add',
#     seasonal='add',
#     seasonal_periods=12
# ).fit()

# # Forecast next 24 months
# forecast = model.forecast(24)

# # Plot original, fitted, and forecast values
# plt.figure(figsize=(12, 6))
# plt.plot(df.index, df['value'], label='Observed', color='blue')
# plt.plot(model.fittedvalues.index, model.fittedvalues, label='Fitted', color='red')
# plt.plot(forecast.index, forecast, label='Forecast', color='green')
# plt.xlabel("Time")
# plt.ylabel("Sales ($ Millions)")
# plt.title("Monthly Antidiabetic Drug Sales Forecast")
# plt.legend()
# plt.tight_layout()
# plt.show()
