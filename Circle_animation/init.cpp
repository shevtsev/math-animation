#include "init.hpp"
inline bool operator <= (Vector2f a, Vector2f b) {
	return a.x <= b.x && a.y <= b.y;
}
inline bool operator >= (Vector2f a, Vector2f b) {
	return a.x > b.x && a.y > b.y;
}
inline bool operator > (Vector2f a, Vector2f b) {
	return a.x >= b.x || a.y >= b.y;
}
inline bool operator < (Vector2f a, Vector2f b) {
	return a.x < b.x || a.y < b.y;
}
void init::init_objs(CircleShape& circle) {
	circle.setRadius(radius);
	circle.setPointCount(1000);
	circle.setFillColor(Color(0xb9, 0x71, 0x29));
}
void init::move_okr() {
	for (int i = 0; i < n; ++i) {
		Vector2f n_pos = { okr_rad + okr_rad * cosf(rad[i]),
			okr_rad + okr_rad * sinf(rad[i]) };
		Vector2f pos = okr[i].getPosition();
		if ((i > n / 2 && pos >= param[i]) || (pos < param[i] && i <= n / 2) || (pos.x < param[i].x && pos.y > param[i].y))
			okr[i].move(speed * cosf(rad[i]), -speed * sinf(rad[i]));
		else {
			okr[i].move(-speed * cosf(rad[i]), speed * sinf(rad[i]));
			param[i].x -= speed * cosf(rad[i]);
			param[i].y += speed * sinf(rad[i]);
		}
		if ((i > n / 2 && param[i] > n_pos) || (param[i] <= n_pos && i < n / 2))
			param[i] = { okr_rad - okr_rad * cosf(rad[i]),
			okr_rad - okr_rad * sinf(rad[i]) };
		else if (i == n / 2 && param[i].x <= 0)
			param[i] = { okr_rad * 2, okr_rad};
	}
}
void init::draw_circle_el() {
	init_objs(Circle);
	for (int i = 0; i < n; ++i) {
		okr[i].setRadius(okr_radius);
		okr[i].setPointCount(1000);
		okr[i].setFillColor(Color(0x5a, 0x4a, 0x3a));
		okr[i].setPosition(Vector2f(okr_rad + (okr_rad / 2) * cosf(radians),
			okr_rad / 2 + (okr_rad / 2) * sinf(radians)));
		radians += PI / (n / 2);
		cnt += okr_rad / (n / 2);
		lines[i].setSize(Vector2f(diameter, 2)), lines[i].setFillColor(Color(0x50, 0x2e, 0x32));
	}
	radians = PI / 2;
	for (int i = 0; i < n; ++i) {
		lines[i].setPosition(Vector2f(radius + radius * cosf(radians),
			radius + radius * sinf(radians)));
		lines[i].setRotation(180.f - radians * 180.f / PI);
		radians += PI / n;
		rad[i] = lines[i].getRotation() * PI / 180.f;
		param[i] = { okr_rad - okr_rad * cosf(rad[i]), okr_rad - okr_rad * sinf(rad[i]) };
	}
	param[n / 2] = { okr_rad * 2, okr_rad }, param[0] = { okr_rad, 0 };
}
void init::Draw(RenderWindow& window) {
	if (!Mouse::isButtonPressed(Mouse::Left))
		move_okr();
	window.draw(Circle);
	for (int i = 0; i < n; ++i)
		window.draw(lines[i]);
	for (int i = 0; i < n; ++i)
		window.draw(okr[i]);
}
