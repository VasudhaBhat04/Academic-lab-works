# -------------------------------
# 1. Load Required Libraries
# -------------------------------
library(class)
library(caret)
library(ggplot2)
library(plotly)
library(dplyr)

# -------------------------------
# 2. Load Dataset
# -------------------------------
<<<<<<< HEAD
data(iris)
head(iris)
=======
data <- read.csv("Mall_Customers.csv")
>>>>>>> a02430d9ccdb1630717044abe6d1755815112e33

# -------------------------------
# 3. Normalize Numeric Columns
# -------------------------------
normalize <- function(x) {
  return((x - min(x)) / (max(x) - min(x)))
}
iris_norm <- as.data.frame(lapply(iris[1:4], normalize))
iris_norm$Species <- iris$Species

# -------------------------------
# 4. Train-Test Split
# -------------------------------
set.seed(123)
index <- createDataPartition(iris_norm$Species, p = 0.7, list = FALSE)
train_data <- iris_norm[index, ]
test_data <- iris_norm[-index, ]

# -------------------------------
# 5. KNN Classification
# -------------------------------
knn_pred <- knn(train = train_data[1:4],
                test = test_data[1:4],
                cl = train_data$Species,
                k = 5)

# -------------------------------
# 6. Evaluation
# -------------------------------
confusionMatrix(knn_pred, test_data$Species)

# -------------------------------
# 7. 2D Visualization using ggplot2
# -------------------------------
ggplot(iris_norm, aes(x = Sepal.Length, y = Sepal.Width, color = Species)) +
  geom_point(size = 3, alpha = 0.8) +
  labs(title = "Iris Flower Species (2D View)",
       x = "Sepal Length", y = "Sepal Width") +
  theme_minimal()

<<<<<<< HEAD
# -------------------------------
# 8. 3D Visualization using Plotly
# -------------------------------
plot_ly(iris_norm, 
        x = ~Petal.Length, 
        y = ~Petal.Width, 
        z = ~Sepal.Length, 
        color = ~Species,
        colors = c('#FF5733','#33FF57','#3357FF'),
        type = 'scatter3d',
        mode = 'markers') %>%
  layout(title = "Iris Species in 3D Space")
=======
library(plotly)
print(
plot_ly(data_norm, x = ~Age, y = ~Income, z = ~Score,
        color = ~Segment, colors = c('#FF5733','#33FF57','#3357FF','#FF33A1'),
        type = 'scatter3d', mode = 'markers')
)
>>>>>>> a02430d9ccdb1630717044abe6d1755815112e33
