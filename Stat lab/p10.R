# Data
sales <- c(2, 4, 6, 9, 12, 34, 45)
Tv <- c(1, 2, 4, 7, 9, 11, 15)

# Create a data frame
data <- data.frame(sales, Tv)

# Linear regression model
model <- lm(sales ~ Tv, data = data)

# Model summary
summary(model)

# Extract intercept and slope
intercept <- coef(model)[1]
slope <- coef(model)[2]

# Print coefficients
cat("Intercept:", intercept, "\n")
cat("Slope:", slope, "\n")

# Plot

plot(data$Tv, data$sales,
     main = "Sales vs TV Advertising Budget",
     xlab = "TV Advertising Budget",
     ylab = "Sales Units",
     pch = 19,
     col = "blue")

# Add regression line
abline(model, col = "red", lwd = 2)
cat("Interpretation:\n")
cat("Mean difference (1980 - 1970): ", mean(fish_data$Price_1980 - fish_data$Price_1970), "\n")
cat("95% confidence interval of difference: ", t_test_result$conf.int, "\n")
