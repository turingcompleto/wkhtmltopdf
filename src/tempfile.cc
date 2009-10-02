//-*- mode: c++; tab-width: 4; indent-tabs-mode: t; c-file-style: "stroustrup"; -*-
// This file is part of wkhtmltopdf.
//
// wkhtmltopdf is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// wkhtmltopdf is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with wkhtmltopdf.  If not, see <http://www.gnu.org/licenses/>.
#include "tempfile.hh"
#include <QUuid>
/*!
  \file tempfile.hh
  \brief Defines the TempFile class
*/


/*!
  \class TempFile
  \brief Class responsible for creating and deleting temporery files
*/
TempFile::TempFile() {
}

TempFile::~TempFile() {
	remove();
}

/*!
  \brief Create a new temporery file, deleteing the old if one exists
  \param ext The extention of the temporery file
  \returns Path of the new temporery file
*/
QString TempFile::create(const QString & ext) {
	remove();
	path = QDir::tempPath()+"/wktemp"+QUuid::createUuid().toString()+ext;
	return path;
}

/*!
  \brief Remove the temporery file hold by this object it it exists
*/
void TempFile::remove() {
	if (!path.isEmpty())						
		QFile::remove(path);
	path="";
}
