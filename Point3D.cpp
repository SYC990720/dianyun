// Point3D.cpp: implementation of the Point3D class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PointCloud.h"
#include "Point3D.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Point3D::Point3D():x(0) , y(0) , z(0) , w(1)
{

}

Point3D::~Point3D()
{

}
Point3D Point3D::operator + (const Point3D &point3D)
{
	Point3D p;
	p.x = x + point3D.x;
	p.y = y + point3D.y;
	p.z = z + point3D.z;
	return p;
}

Point3D Point3D::operator - (const Point3D &point3D)
{
	Point3D p;
	p.x = x - point3D.x;
	p.y = y - point3D.y;
	p.z = z - point3D.z;
	return p;
}

Point3D Point3D::operator / (const int &sum)
{
	if (sum <= 0)
		return (*this);
	Point3D p;
	p.x = x / sum;
	p.y = y / sum;
	p.z = z / sum;
	return p;
}

Point3D Point3D::operator * (const int &sum)
{
	Point3D p;
	p.x = x * sum;
	p.y = y * sum;
	p.z = z * sum;
	return p;
}

Point3D Point3D::operator += (const Point3D &point3D)
{
	x = x + point3D.x;
	y = y + point3D.y;
	z = z + point3D.z;
	return (*this);
}

Point3D Point3D::operator -= (const Point3D &point3D)
{
	x = x - point3D.x;
	y = y - point3D.y;
	z = z - point3D.z;
	return (*this);
}

Point3D Point3D::operator /= (const int &sum)
{
	if (sum <= 0)
		return (*this);
	x = x / sum;
	y = y / sum;
	z = z / sum;
    return (*this);
}

Point3D Point3D::operator *= (const int &sum)
{
	x = x * sum;
	y = y * sum;
	z = z * sum;
    return (*this);
}