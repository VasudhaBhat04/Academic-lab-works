
library(class)
library(caret)
library(ggplot2)
library(plotly)
library(dplyr)

data(iris)
head(iris)

normalize <- function(x) {
  return((x - min(x)) / (max(x) - min(x)))
}
iris_norm <- as.data.frame(lapply(iris[1:4], normalize))
iris_norm$Species <- iris$Species

set.seed(123)
index <- createDataPartition(iris_norm$Species, p = 0.7, list = FALSE)
train_data <- iris_norm[index, ]
test_data <- iris_norm[-index, ]


knn_pred <- knn(train = train_data[1:4],
                test = test_data[1:4],
                cl = train_data$Species,
                k = 5)

confusionMatrix(knn_pred, test_data$Species)


ggplot(iris_norm, aes(x = Sepal.Length, y = Sepal.Width, color = Species)) +
  geom_point(size = 3, alpha = 0.8) +
  labs(title = "Iris Flower Species (2D View)",
       x = "Sepal Length", y = "Sepal Width") +
  theme_minimal()

plot_ly(iris_norm, 
        x = ~Petal.Length, 
        y = ~Petal.Width, 
        z = ~Sepal.Length, 
        color = ~Species,
        colors = c('#FF5733','#33FF57','#3357FF'),
        type = 'scatter3d',
        mode = 'markers') %>%
  layout(title = "Iris Species in 3D Space")
