
# Load required libraries
library(readxl)
library(ggplot2)
library(reshape2)

# Read the Excel file
fish_data <- read_excel("fishstory.xls")

# Summary of Price in 1970
cat("Summary of Prices in 1970:\n")
print(summary(fish_data$Price_1970))

# Summary of Price in 1980
cat("Summary of Prices in 1980:\n")
print(summary(fish_data$Price_1980))

# Paired t-test (same fish types across years)
t_test_result <- t.test(fish_data$Price_1980, fish_data$Price_1970, paired = TRUE)

cat("Paired t-test Results:\n")
print(t_test_result)

cat("Interpretation:\n")
cat("Mean difference (1980 - 1970): ", mean(fish_data$Price_1980 - fish_data$Price_1970), "\n")
cat("95% confidence interval of difference: ", t_test_result$conf.int, "\n")

#optional plot
# Melt data for ggplot (long format)
fish_long <- melt(fish_data, 
                  id.vars = "Type_fish",
                  measure.vars = c("Price_1970", "Price_1980"),
                  variable.name = "Year",
                  value.name = "Price")

# Line + point plot of prices across years

ggplot(fish_long, aes(x = Year, y = Price, group = Type_fish, color = Type_fish)) +
  geom_line(size = 1) +
  geom_point(size = 2) +
  labs(title = "Fish Prices 1970 vs 1980", x = "Year", y = "Price") +
  theme_minimal() +
  theme(legend.position = "none")
