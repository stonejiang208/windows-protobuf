

protoc  --cpp_out=dllexport_decl=GP_PROTOC_Export:. Demo.proto
sed -i '21 c #include "GP_Protoc_Export.h"' Demo.pb.h
