#include "SphereCollider.h"
#include "math.h"

SphereCollider::SphereCollider(T_location location, float radius) {
	
	this->location.x = location.x;
	this->location.y = location.y;

	this->radius = radius;
	
}

	//�����o�ϐ��ɕύX�������Ȃ����͂��炩����const��t���Ă���

	//SphereCollider�^���m�̓����蔻��
bool SphereCollider::HitSphere(const SphereCollider* collider) const {
	//�������瑊��ւ̃x�N�g�����v�Z����
	//�v�Z�ŏo�����x�N�g���̑傫����
	//�����Ƒ���̔��a�̍��v���
	//�x�N�g���̑傫������������΁A�������Ă���

	//�����Ƒ���Ƃ̊Ԃ̃x�N�g�����v�Z
	float vectorX = fabsf(this->location.x - collider->GetLocation().x);
	float vectorY = fabsf(this->location.y - collider->GetLocation().y);

	//�x�N�g���̑傫�����v�Z
	float vectorLength = (vectorX * vectorX) + (vectorY * vectorY);
	vectorLength = sqrtf(vectorLength);

	float sumRadius = radius + collider->GetRadius();

	//�����蔻��̌��ʂ��i�[
	bool ret = vectorLength < sumRadius;

	return ret;

	}

	//���S���W�̎擾
	T_location SphereCollider::GetLocation() const {
		return location;
	}

	//���S���W�̐ݒ�
	void SphereCollider::SetLocation(T_location location) {
		this->location.x = location.x;
		this->location.y = location.y;
	}

	//���a�̎擾
	float SphereCollider::GetRadius() const {
		return radius;
	}