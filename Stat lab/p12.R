# Load dataset
data(mtcars)

# 1. One-way ANOVA
anova_result <- aov(mpg ~ factor(cyl), data = mtcars)
print("=== ANOVA Result ===")
print(summary(anova_result))

# 2. Kruskal-Wallis test (non-parametric ANOVA alternative)
print("=== Kruskal-Wallis Test ===")
print(kruskal.test(mpg ~ factor(cyl), data = mtcars))

# 3. Pairwise Wilcoxon tests (instead of manual subset_data)
print("=== Pairwise Wilcoxon (Mann-Whitney) Tests ===")
print(pairwise.wilcox.test(mtcars$mpg, mtcars$cyl,exact=FALSE))

# 4. Boxplot for visualization

boxplot(mpg ~ factor(cyl), data = mtcars,
        main = "MPG by Cylinder Count",
        xlab = "Cylinders", ylab = "MPG",
        col = c("skyblue","orange","green"))
