#include "Records.h"
#include <cassert>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "Util.h"

void Records::Insert(Element & element)
{
	//autoincrement record count and use it as indes (id)
	element.SetId(elements.size() + 1);
	elements.emplace_back(element);
	++nRecords;
}

void Records::Insert(Element && element)
{
	Insert(element);
}

void Records::Insert(unsigned int requi, std::string originDate, std::string requestDate, std::string authorizedDate, 
	unsigned long amount, bool hasTax)
{
	time_t tmpAuthDate = 0;
	if (authorizedDate.size() == 10)
	{
		tmpAuthDate = Util::ConvertDate(authorizedDate);
	}

	Element element((uint16_t)requi, Util::ConvertDate(originDate), Util::ConvertDate(requestDate), 
		tmpAuthDate, amount, hasTax);

	element.SetId(elements.size() + 1 );
	elements.emplace_back(element);
	++nRecords;
}

void Records::SaveToFile()
{
	std::ofstream file("datos.txt", std::ios::binary);
	assert(file);
	if (file)
	{
		nRecords = (unsigned int)elements.size();
		//file.write(reinterpret_cast<char*>(&nRecords), sizeof(nRecords) );

		if (nRecords > 0)
		{
			WriteHeader( file );

			for (auto& e : elements)
			{
				uint16_t tmpId = e.GetId();
				uint16_t tmpRequi = e.GetRequi();
				time_t tmpOrigin = e.GetOriginDate();
				time_t tmpRequest = e.GetRequestDate();
				time_t tmpAuth = e.GetAuthorizedDate();
				uint32_t tmpAmount = e.GetAmount();
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
		//file.read(reinterpret_cast<char*>(&nTmpRecords), sizeof(nTmpRecords));
		if ( ReadHeader( file ) )
		{
			if ( nRecords > 0 )
			{
				elements.clear();

				for ( unsigned int i = 0; i < nRecords && file.good(); ++i )
				{
					uint16_t tmpId = 0;
					uint16_t tmpRequi = 0;
					time_t tmpOrigin = 0;
					time_t tmpRequest = 0;
					time_t tmpAuth = 0;
					uint32_t tmpAmount = 0;
					bool tmpTaxed;
					bool tmpAuthorized;

					file.read( reinterpret_cast<char*>(&tmpId), sizeof( tmpId ) );
					file.read( reinterpret_cast<char*>(&tmpRequi), sizeof( tmpRequi ) );
					file.read( reinterpret_cast<char*>(&tmpOrigin), sizeof( tmpOrigin ) );
					file.read( reinterpret_cast<char*>(&tmpRequest), sizeof( tmpRequest ) );
					file.read( reinterpret_cast<char*>(&tmpAuth), sizeof( tmpAuth ) );
					file.read( reinterpret_cast<char*>(&tmpAmount), sizeof( tmpAmount ) );
					file.read( reinterpret_cast<char*>(&tmpTaxed), sizeof( tmpTaxed ) );
					file.read( reinterpret_cast<char*>(&tmpAuthorized), sizeof( tmpAuthorized ) );

					Element tmpElement( tmpRequi, tmpOrigin, tmpRequest, tmpAuth,
						tmpAmount, tmpTaxed, tmpAuthorized );

					tmpElement.SetId( tmpId );
					elements.emplace_back( tmpElement );
				}
			}
		}
	}
}

void Records::ListRequi(bool ordered)
{
	if (elements.size() > 0)
	{
		if (ordered)
		{
			std::sort(elements.begin(), elements.end());
		}

		std::copy(elements.begin(), elements.end(), std::ostream_iterator<Element>(std::cout, "\n") );
	}
}

void Records::WriteHeader( std::ostream & out )
{
	out.write( sSignature, sizeof( sSignature ) );
	out.write( const_cast<char*>(&nVersionMajor), sizeof( nVersionMajor ) );
	out.write( const_cast<char*>(&nVersionMinor), sizeof( nVersionMinor ) );
	out.write( reinterpret_cast<char*>(&nRecords), sizeof( nRecords ) );
}

bool Records::ReadHeader( std::istream & in )
{
	char sTmpSig[2];
	char nTmpVerMaj;
	char nTmpVerMin;

	in.read( sTmpSig, sizeof( sTmpSig ) );

	if ( sTmpSig[0] != sSignature[0] &&
		sTmpSig[1] != sSignature[1] )
	{
		std::cout << "Wrong signature\n";
		return false;
	}

	in.read( &nTmpVerMaj, sizeof( nTmpVerMaj ) );
	in.read( &nTmpVerMin, sizeof( nTmpVerMin ) );

	if ( nVersionMajor != nTmpVerMaj || nVersionMinor != nTmpVerMin )
	{
		std::cout << "Wrong version\n";
		return false;
	}

	in.read( reinterpret_cast<char*>(&nRecords), sizeof( nRecords ) );

	return true;
}
