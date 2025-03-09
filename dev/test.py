#!/usr/bin/env python3
import numpy as np

def calculate_accelerometer_covariance(x_data, y_data, z_data):
    """
    Calculate the 3x3 covariance matrix for 3-axis accelerometer data.
    
    Parameters:
    x_data (array-like): Time series data for x-axis (e.g., in g or m/s^2)
    y_data (array-like): Time series data for y-axis
    z_data (array-like): Time series data for z-axis
    
    Returns:
    cov_matrix (np.ndarray): 3x3 covariance matrix with variances and covariances
    """
    # Ensure inputs are numpy arrays and have the same length
    x = np.asarray(x_data, dtype=float)
    y = np.asarray(y_data, dtype=float)
    z = np.asarray(z_data, dtype=float)
    
    if not (x.shape == y.shape == z.shape):
        raise ValueError("All input arrays must have the same length")
    
    # Stack the data into a 3xN matrix (3 axes, N samples)
    data = np.vstack((x, y, z))
    
    # Calculate the covariance matrix
    # np.cov assumes rows are variables (axes) and columns are observations
    # ddof=1 uses sample covariance (n-1 denominator), common for sensor data
    cov_matrix = np.cov(data, ddof=1)
    
    return cov_matrix

# Example usage
if __name__ == "__main__":
    # Simulated accelerometer data (e.g., stationary with noise)
    np.random.seed(42)  # For reproducibility
    n_samples = 1000
    x_data = np.random.normal(loc=0, scale=0.01, size=n_samples)  # Noise ~0.01 g
    y_data = np.random.normal(loc=0, scale=0.01, size=n_samples) + 0.02 * x_data  # Some correlation with x
    z_data = np.random.normal(loc=0, scale=0.01, size=n_samples)

    # Calculate covariance matrix
    cov_matrix = calculate_accelerometer_covariance(x_data, y_data, z_data)
    
    # Print the result
    print("Covariance Matrix:")
    print(cov_matrix)
    
    # Optional: Extract specific terms
    print("\nVariances:")
    print(f"Var(x) = {cov_matrix[0, 0]:.6f}")
    print(f"Var(y) = {cov_matrix[1, 1]:.6f}")
    print(f"Var(z) = {cov_matrix[2, 2]:.6f}")
    print("\nCovariances:")
    print(f"Cov(x, y) = {cov_matrix[0, 1]:.6f}")
    print(f"Cov(x, z) = {cov_matrix[0, 2]:.6f}")
    print(f"Cov(y, z) = {cov_matrix[1, 2]:.6f}")