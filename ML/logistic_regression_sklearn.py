import numpy as np
from sklearn import linear_model

model = linear_model.LogisticRegression()


training_data_x = [[1, 2], [2, 1], [3, 4], [5, 7], [11, 0], [1, 9], [4, 1]]
training_data_y = [0, 1, 0, 0, 1, 0, 1] # 1 if x[0] > x[1]

model.fit(training_data_x, training_data_y)

test_data_x = [[1, 2], [5, 3], [3, 3], [7, 17], [7, 2]]

predictions = model.predict(test_data_x)

print predictions
# output = [0 1 0 0 1]
