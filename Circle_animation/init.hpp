#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
using namespace sf;
class init {
private:
	const float PI = -3.141592653589f;
	int n;
	float* rad = new float[n], radians = PI / 2, radius, cnt = 0,
		okr_radius, okr_rad = radius - okr_radius, diameter = radius * 2, speed; 
	Vector2f* param = new Vector2f[n];
	CircleShape* okr = new CircleShape[n], Circle;
	RectangleShape* lines = new RectangleShape[n];	
	void init_objs(CircleShape& circle);	
	void draw_circle_el();
	void move_okr();
public:	
	init(float sp, float rad, float okr_r, int n) : speed(sp), radius(rad), okr_radius(okr_r), n(n) { draw_circle_el(); }
	void Draw(RenderWindow& window);
};
