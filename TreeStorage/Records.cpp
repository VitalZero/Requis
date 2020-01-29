#include "Records.h"
#include <cassert>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <iostream>

void Records::Insert(Element & element)
{
	element.SetId(++nRecords);
	elements.emplace_back(element);
}

void Records::SaveToFile()
{
	std::ofstream file("datos.txt", std::ios::binary);
	assert(file);
	if (file)
	{
		nRecords = (unsigned int)elements.size();
		file.write(reinterpret_cast<char*>(&nRecords), sizeof(nRecords) );

		if (nRecords > 0)
		{
			for (auto& e : elements)
			{
				uint32_t tmpId = e.GetId();
				uint32_t tmpRequi = e.GetRequi();
				time_t tmpOrigin = e.GetOriginDate();
				time_t tmpRequest = e.GetRequestDate();
				time_t tmpAuth = e.GetAuthorizedDate();
				uint64_t tmpAmount = e.GetAmount();
				bool tmpTaxed = e.IsTaxed();
				bool tmoAuthorized = e.IsAuthorized();

				file.write(reinterpret_cast<char*>(&tmpId), sizeof(tmpId));
				file.write(reinterpret_cast<char*>(&tmpRequi), sizeof(tmpRequi));
				file.write(reinterpret_cast<char*>(&tmpOrigin), sizeof(tmpOrigin));
				file.write(reinterpret_cast<char*>(&tmpRequest), sizeof(tmpRequest));
				file.write(reinterpret_cast<char*>(&tmpAuth), sizeof(tmpAuth));
				file.write(reinterpret_cast<char*>(&tmpAmount), sizeof(tmpAmount));
				file.write(reinterpret_cast<char*>(&tmpTaxed), sizeof(tmpTaxed));
				file.write(reinterpret_cast<char*>(&tmoAuthorized), sizeof(tmoAuthorized));
			}
		}
	}

}

void Records::LoadFromFile()
{
	std::ifstream file("datos.txt", std::ios::binary);
	assert(file);

	if (file)
	{
		unsigned int nTmpRecords = 0;
		nRecords = 0;
		file.read(reinterpret_cast<char*>(&nTmpRecords), sizeof(nTmpRecords));
		if (nTmpRecords > 0)
		{
			elements.clear();

			for (unsigned int i = 0; i < nTmpRecords && file.good(); ++i)
			{
				uint32_t tmpId = 0;
				uint32_t tmpRequi = 0;
				time_t tmpOrigin = 0;
				time_t tmpRequest = 0;
				time_t tmpAuth = 0;
				uint64_t tmpAmount = 0;
				bool tmpTaxed;
				bool tmpAuthorized;

				file.read(reinterpret_cast<char*>(&tmpId), sizeof(tmpId));
				file.read(reinterpret_cast<char*>(&tmpRequi), sizeof(tmpRequi));
				file.read(reinterpret_cast<char*>(&tmpOrigin), sizeof(tmpOrigin));
				file.read(reinterpret_cast<char*>(&tmpRequest), sizeof(tmpRequest));
				file.read(reinterpret_cast<char*>(&tmpAuth), sizeof(tmpAuth));
				file.read(reinterpret_cast<char*>(&tmpAmount), sizeof(tmpAmount));
				file.read(reinterpret_cast<char*>(&tmpTaxed), sizeof(tmpTaxed));
				file.read(reinterpret_cast<char*>(&tmpAuthorized), sizeof(tmpAuthorized));

				Element tmpElement(tmpRequi, tmpOrigin, tmpRequest, tmpAuth, 
					tmpAmount, tmpTaxed, tmpAuthorized);

				tmpElement.SetId(tmpId);
				elements.emplace_back(tmpElement);
				
			}
		}
	}
}

void Records::ListRequi()
{
	if (elements.size() > 0)
	{
		std::sort(elements.begin(), elements.end());

		//test code
		//auto result = std::find_if(elements.begin(), elements.end(), 
		//	[](const Element& e)
		//	{
		//		return e.GetId() == 2;
		//	});
		//if (result != elements.end())
		//{
		//	std::cout << result->GetRequi() << std::endl;
		//}

		std::copy(elements.begin(), elements.end(), std::ostream_iterator<Element>(std::cout, "\n") );
	}
}