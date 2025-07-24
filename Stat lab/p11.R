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
