# Scores of 10 students
smip_scores <- c(70, 46, 94, 34, 20, 86, 18, 12, 56, 64, 42)
dbms_scores <- c(60, 66, 90, 46, 16, 98, 24, 8, 32, 54, 52)

# Spearman Rank Correlation Test
result <- cor.test(smip_scores, dbms_scores, method = "spearman")

# Print results
cat("Spearman Rank Correlation Coefficient:", round(result$estimate, 4), "\n")
cat("P-value:", round(result$p.value, 4), "\n")


#optional plot
data <- data.frame(smip_scores, dbms_scores)

plot(smip_scores, dbms_scores,
     main = "scatter plot of smip vs dbms",
     xlab = "smip",
     ylab = "dbms",
     pch = 19, col = "blue")

abline(lm(smip_scores ~ dbms_scores, data = data), col = "red", lwd = 2)
