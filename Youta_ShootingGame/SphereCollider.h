#pragma once
#include "common.h"

class SphereCollider
{
private:
	T_location location;	//���S���W
	float radius;			//���a

public://�R���X�g���N�^�͕�����₷���悤�ɓ���public�ł������ꏊ�𕪂���
	SphereCollider(T_location location, float radius);

public:
	//�����o�ϐ��ɕύX�������Ȃ����͂��炩����const��t���Ă���
	bool HitSphere(const SphereCollider* collider) const;//SphereCollider�^���m�̓����蔻��
	T_location GetLocation() const;//���S���W�̎擾
	void SetLocation(T_location location);//���S���W�̐ݒ�
	float GetRadius() const;//���a�̎擾

};

