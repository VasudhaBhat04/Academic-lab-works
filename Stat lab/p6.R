# Load required libraries 
library(ggplot2) 
library(dplyr) 
library(readr) 
# Load the dataset and find the summary statistics 
data <- read_csv("medicalmalpractice.csv") 
print(summary(data$Amount))
# 2. Histogram of claim amount (log scale) 

ggplot(data, aes(x = log10(Amount))) + 
geom_histogram(fill = "lightblue", bins = 20) + 
labs(title = "Histogram of Claim Amounts (Log Scale)", x = "Log Amount", y = 
"Frequency") 


# 3. Boxplot for top 3 specialties 
top3 <- data %>% count(Specialty, sort = TRUE) %>% top_n(3, n) %>% 
pull(Specialty) 
ggplot(filter(data, Specialty %in% top3), aes(x = Specialty, y = Amount, fill = 
Specialty)) + 
geom_boxplot() + scale_y_log10() + 
labs(title = "Claim Amounts by Top 3 Specialties", x = "Specialty", y = 
"Amount") 
# 4. Percentage of specific specialties 
total <- nrow(data) 
cat("Anesthesiology:", round(sum(data$Specialty == "Anesthesiology") / total * 
100, 2), "%\n") 
cat("Dermatology:", round(sum(data$Specialty == "Dermatology") / total * 100, 
2), "%\n") 
cat("Orthopedic Surgery:", round(sum(data$Specialty == "Orthopedic Surgery") / 
total * 100, 2), "\n") 
# 5. Correlation between Age and Amount 
result <- cor.test(data$Age, data$Amount)
cat("Age vs Amount correlation:\n")
cat("Correlation Coefficient:", round(result$estimate, 4), "\n")
cat("P-value:", result$p.value, "\n")