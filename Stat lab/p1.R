data(mtcars)                     # Loads the mtcars dataset
head(mtcars)                     # Shows the first 6 rows
correlation <- cor(mtcars$mpg, mtcars$wt)
print(paste("correlation between mpg and weight is:", round(correlation,2)))

plot(mtcars$wt, mtcars$mpg,
     main = "scatter plot of mpg vs weight",
     xlab = "weight (1000lbs)",
     ylab = "miles per gallon (MPG)",
     pch = 19, col = "blue")

abline(lm(mpg ~ wt, data = mtcars), col = "red", lwd = 2)
