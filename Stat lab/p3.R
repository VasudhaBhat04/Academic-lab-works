# Load necessary libraries 
library(ggplot2) 
library(readr) 
library(dplyr) 

# Load the dataset 
df <- read.csv("pricequotes.csv") 

# 1. Summary Statistics for Mary and Barry 
print(summary(df))

# 2. Standard Deviation and Standard Error for Mary
sd_mary <- sd(df$Mary.Price)
se_mary <- sd_mary / sqrt(length(df$Mary.Price))

# 3. Standard Deviation and Standard Error for Barry
sd_bary <- sd(df$Barry.Price)
se_bary <- sd_bary / sqrt(length(df$Barry.Price))

# Print results
cat("Mary's SD:", round(sd_mary, 2), "| SE:", round(se_mary, 2), "\n")
cat("Barry's SD:", round(sd_bary, 2), "| SE:", round(se_bary, 2), "\n")


# 4. Boxplot 

ggplot(df, aes(x = "Barry", y = `Barry.Price`)) + 
geom_boxplot(fill = "skyblue") + 
geom_boxplot(aes(x = "Mary", y = `Mary.Price`), fill = "lightgreen") + 
labs(title = "Boxplot of Price Quotes", x = "Person", y = "Price")
