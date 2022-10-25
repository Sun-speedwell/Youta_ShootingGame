#pragma once
#include "common.h"

class SphereCollider
{
private:
	T_location location;	//中心座標
	float radius;			//半径

public://コンストラクタは分かりやすいように同じpublicでも書く場所を分ける
	SphereCollider(T_location location, float radius);

public:
	//メンバ変数に変更を加えない物はあらかじめconstを付けておく
	bool HitSphere(const SphereCollider* collider) const;//SphereCollider型同士の当たり判定
	T_location GetLocation() const;//中心座標の取得
	void SetLocation(T_location location);//中心座標の設定
	float GetRadius() const;//半径の取得

};

