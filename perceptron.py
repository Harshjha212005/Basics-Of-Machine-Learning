def perceptron(w1, w2, bias, learning_rate, gate):
    i = 0

    while i < 4:
        a = i & 1
        b = (i >> 1) & 1

        if gate.lower() == "and":
            target = a & b
        elif gate.lower() == "or":
            target = a | b
        else:
            print("Invalid gate!")
            return w1, w2, bias

        net = w1 * a + w2 * b + bias
        output = 1 if net >= 0 else 0

        if output == target:
            i += 1
        else:
            error = target - output

            w1 = w1 + learning_rate * error * a
            w2 = w2 + learning_rate * error * b
            bias = bias + learning_rate * error

            i = 0 

    return w1, w2, bias


# ---- Main Program ----
gate = input("Enter gate (and/or): ")
w1 = eval(input("Enter w1: "))
w2 = eval(input("Enter w2: "))
bias = eval(input("Enter bias: "))
lr = eval(input("Enter learning rate: "))

w1, w2, bias = perceptron(w1, w2, bias, lr, gate)

print("\nFinal Weights:")
print("w1 =", w1)
print("w2 =", w2)
print("bias =", bias)