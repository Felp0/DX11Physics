#include "Apperance.h"

Apperance::Apperance(Geometry geometry, Material material)
{
	_geometry = geometry;
	_material = material;
	_textureRV = nullptr;
}

void Apperance::Draw(ID3D11DeviceContext* pImmediateContext)
{
	pImmediateContext->IASetVertexBuffers(0, 1, &_geometry.vertexBuffer, &_geometry.vertexBufferStride, &_geometry.vertexBufferOffset);
	pImmediateContext->IASetIndexBuffer(_geometry.indexBuffer, DXGI_FORMAT_R16_UINT, 0);

	pImmediateContext->DrawIndexed(_geometry.numberOfIndices, 0, 0);
}