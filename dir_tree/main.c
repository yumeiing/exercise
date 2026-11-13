#include <string.h>
#include <stdio.h>
#include <dirent.h>

void print_file(const char *fileName, int fileType, int indent){
	printf("|-");
	while(--indent) printf("--");
//	--indent;
//	printf("%*c", indent * 2, '-');
	switch(fileType){
	case DT_DIR:
		printf("\e[0;34m%s/\e[0m\n", fileName);
		break;
	case DT_LNK:
		printf("\e[0;33m%s/\e[0m\n", fileName);
		break;
	case DT_UNKNOWN:
		printf("\e[0;31m%s/\e[0m\n", fileName);
		break;
	default:
		printf("%s\n", fileName);
	}
}

int walk(const char *path,int indent){
	DIR *dir; 
	if((dir = opendir(path)) == NULL){
		fprintf(stderr,"can't open dir: %s\n",path);;
		return 1;
	}
	struct dirent *dp;
	while((dp = readdir(dir)) != NULL){
		const char *fn = dp->d_name,
			  ft = dp->d_type;

		if(strcmp(fn, ".") == 0 || strcmp(fn, "..") == 0){
			continue;
		}

		print_file(fn, ft, indent);	
		if(ft == DT_DIR){
			size_t len = strlen(path) + strlen(fn) + 2;
			char sub_path[len];
			snprintf(sub_path, len, "%s/%s", path,fn);
			walk(sub_path, indent + 1);
		}
	}

	closedir(dir);
	return 0;
}

int main(int argc, char **argv){
	const char *path = ".";

	if(argc > 1){
		path = argv[1];
	}

	printf("%s\n",path);
	int err = walk(path, 1);
	return err;
}



