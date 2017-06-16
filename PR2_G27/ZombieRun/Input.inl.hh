#pragma once
#include <conio.h>

namespace enti
{
	enum class InputKey // Represents each key that the player can use
	{
		NONE = -1, a = 65, A = 97, b = 66, B = 98, c = 67, C = 99, d = 68, D = 100, e = 69, E = 101, f = 70, F = 102, g = 71, G = 103, h = 72, H = 104, i = 73, I = 105, j = 74, J = 106,
		k = 75, K = 107, l = 76, L = 108, m = 77, M = 109, n = 78, N = 110, o = 79, O = 111, p = 80, P = 112, q = 81, Q = 113, r = 82, R = 114 ,s = 83, S = 115, t = 84, T = 116,
		u = 85, U = 117, v = 86, V = 118, w = 87, W = 119, x = 88, X = 120, y = 89, Y = 121, z = 122, Z = 90,
		NUM0 = 48, NUM1, NUM2, NUM3, NUM4, ENTER = 13, SPACEBAR = 32, ESC = 27
	};

	inline InputKey getInputKey() // Returns the key that has been pressed
	{
		return _kbhit() ? static_cast<InputKey>(_getch()) : InputKey::NONE;
	}

	inline void systemPause() // Pauses the execution until a key is pressed
	{
		while (getInputKey() == InputKey::NONE);
	}
};
