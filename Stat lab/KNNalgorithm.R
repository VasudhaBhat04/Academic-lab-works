# -------------------------------
# 1. Load Required Libraries
# -------------------------------
library(ggplot2)
library(class)
library(caret)
library(dplyr)
library(reshape2)
library(gridExtra)
library(GGally)

# -------------------------------
# 2. Load Dataset
# -------------------------------
data <- read.csv("C:/Users/USER/OneDrive/Documents/GitHub/Academics/Stat lab/Mall_Customers.csv")

# -------------------------------
# 3. Basic Preprocessing
# -------------------------------
# We'll use Gender (as factor), Age, Annual Income and Spending Score
data$Gender <- as.factor(data$Gender)

# Normalize numeric features
normalize <- function(x) {
  return((x - min(x)) / (max(x) - min(x)))
}

data_norm <- as.data.frame(lapply(data[, c("Age", "Annual.Income..k..", "Spending.Score..1.100.")], normalize))
colnames(data_norm) <- c("Age", "Income", "Score")

# Add Gender back if needed
data_norm$Gender <- data$Gender

# -------------------------------
# 4. Create Labels & Split Data
# -------------------------------
set.seed(123)
data_norm$Segment <- kmeans(data_norm[, 1:3], centers = 4, nstart = 25)$cluster
data_norm$Segment <- as.factor(data_norm$Segment)

# Split into train/test
index <- createDataPartition(data_norm$Segment, p = 0.7, list = FALSE)
train_data <- data_norm[index, ]
test_data <- data_norm[-index, ]

# -------------------------------
# 5. KNN Model
# -------------------------------
knn_pred <- knn(train = train_data[, 1:3],
                test = test_data[, 1:3],
                cl = train_data$Segment,
                k = 5)

# -------------------------------
# 6. Evaluation
# -------------------------------
confusionMatrix(knn_pred, test_data$Segment)

# -------------------------------
# 7. Visualize Clusters
# -------------------------------
windows()
print(
ggplot(data_norm, aes(x = Income, y = Score, color = Segment)) +
  geom_point(size = 3, alpha = 0.7) +
  labs(title = "Customer Segments by Income & Spending Score", x = "Normalized Income", y = "Spending Score") +
  theme_minimal()
)
# Optional: 3D Plot

library(plotly)
print(
plot_ly(data_norm, x = ~Age, y = ~Income, z = ~Score,
        color = ~Segment, colors = c('#FF5733','#33FF57','#3357FF','#FF33A1'),
        type = 'scatter3d', mode = 'markers')
)