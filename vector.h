#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

class PVector {
public:
	float x, y;

	// Constructor
	PVector(float x = 0, float y = 0) : x(x), y(y) {}

	// Add another vector
	PVector add(const PVector& other) const {
		return PVector(x + other.x, y + other.y);
	}

	// Subtract another vector
	PVector sub(const PVector& other) const {
		return PVector(x - other.x, y - other.y);
	}

	// Multiply by a scalar
	PVector mult(float scalar) const {
		return PVector(x * scalar, y * scalar);
	}

	// Divide by a scalar
	PVector div(float scalar) const {
		return PVector(x / scalar, y / scalar);
	}

	// Calculate the magnitude of the vector
	float mag() const {
		return std::sqrt(x * x + y * y);
	}

	// Normalize the vector (make it unit length)
	PVector normalize() const {
		float magnitude = mag();
		return magnitude == 0 ? PVector(0, 0) : PVector(x / magnitude, y / magnitude);
	}

	// Set the magnitude of the vector
	PVector setMag(float newMag) const {
		return normalize().mult(newMag);
	}

	// Copy the vector
	PVector copy() const {
		return PVector(x, y);
	}
};

#endif // VECTOR_H 