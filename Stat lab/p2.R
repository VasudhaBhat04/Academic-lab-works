# Load the built-in dataset mtcars
data(mtcars)

# Load ggplot2 library
library(ggplot2)

# Calculates Pearson correlation between mpg and wt
correlation <- cor(mtcars$mpg, mtcars$wt,method="pearson")  
print(paste("correlation between mpg and weight is:", round(correlation,2)))


# Create Q-Q plot to check normality of mpg

ggplot(data = mtcars, aes(sample = mpg)) + 
  stat_qq() + 
  stat_qq_line() + 
  labs(
    title = "Q-Q Plot for MPG",
    x = "Theoretical Quantiles",
    y = "MPG (Sample)"
  ) +
  theme_minimal()
