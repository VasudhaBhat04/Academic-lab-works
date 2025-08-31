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

#Optional 2 graphs side by side
library(gridExtra)
p1<-ggplot(data = mtcars, aes(sample = mpg)) + 
  stat_qq() + 
  stat_qq_line() + 
  labs(
    title = "Q-Q Plot for MPG",
    x = "Theoretical Quantiles",
    y = "MPG (Sample)"
  ) +
  theme_minimal()

p2<-ggplot(data = mtcars, aes(sample = wt)) + 
  stat_qq() + 
  stat_qq_line() + 
  labs(
    title = "Q-Q Plot for wt",
    x = "Theoretical Quantiles",
    y = "Weight (Sample)"
  ) +
  theme_minimal()


grid.arrange(p1, p2, ncol = 2)
