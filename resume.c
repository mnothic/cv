#include <stdio.h>
#include <time.h>
/*
* This is my CV in C
* Based on resume of https://github.com/klange
* this may show knowledge in
* pointers, structs and references
*/

typedef struct {
	union {
		char * company;
		char * school;
		char * project;
	};
	union {
		char * location;
		char * url;
	};
	union {
		char * title;
		char * program;
	};

	time_t started;
	time_t left;

	char * description[];
} thing_t;

typedef thing_t job_t;
typedef thing_t school_t;
typedef thing_t project_t;

#define CURRENT 0

/* Contact Information */
char * name    = "Jorge A. Medina Oliva";
char * email   = "jorge_at_engine_dot_cl";
char * address = "Located in:\n"
                 "Barcelona Spain & Santiago Chile";

/* Education */
school_t ipla = {
	.school   = "IPLA",
	.location = "Santiago CL",
	.program  = "BS Computer Science",
	.started  = 1109635200,
	.left     = 1325376000,
	.description = {
		"Studies Computer Engineering in Chile",
		"Focused on software engineering courses",
		NULL
	}
};

/* Education */
school_t coursera = {
	.school   = "CS Coursera",
	.location = "Internet",
	.program  = "Continuous learning and practice",
	.started  = 1388530800,
	.left     = CURRENT,
	.description = {
		"Self Learning in CS",
		"Focused Programming and Algorithms",
		"Algebra and calcolous",
		NULL
	}
};

/* Employment History */
job_t amaris = {
	.company  = "Amaris.",
	.location = "Barcelona",
	.title    = "DevOps Groupalia.com",
	.started  = 1426596230,
	.left     = CURRENT,
	.description = {
		"Senior System Administrator",
		"Provided critical improvements in web acceleration and systems performance",
		NULL
	}
};
job_t hp = {
	.company  = "HP services Spain.",
	.location = "Barcelona, ES",
	.title    = "System administrator",
	.started  = 1335830400,
	.left     = 1385769599,
	.description = {
		"This job sucks I take it because arrived to spain and I take the offer it for survive",
		"No programing at all except simple bash scripting, boring",
		NULL
	}
};

job_t eyc = {
	.company  = "EyC",
	.location = "Santiago, CL",
	.title    = "System administrator",
	.started  = 1314835200,
	.left     = 1327881600,
	.description = {
		"Unix/Oracle Solution Engineer",
		"No programing at all except simple bash scripting, boring",
		NULL
	}
};

job_t adem = {
	.company  = "ADEM Inc.",
	.location = "Santiago, CL",
	.title    = "Software Engineering",
	.started  = 1201824000,
	.left     = 1314662400,
	.description = {
		"Develop Intranet and help desk web tools to manage it infrastructure",
		"Develop mdbuilder daemon in C",
		"Develop data transport components in php and after in python",
		"First python contact and build various PoC RPC services",
		"First look to SQLAlchemy Graet framework experience",
		"Extend postfix with triggers in C and python",
		"Great expedition",
		NULL
	}
};

job_t fach = {
	.company  = "FACH",
	.location = "Santiago, CL",
	.title    = "Oracle DBA and developer",
	.started  = 1180656000,
	.left     = 1199145600,
	.description = {
		"Develop in Java, Oracle PL/SQL, Forms and Reports",
		"Develop and fixing finances modules, migrate legacy code to Oracle 10g",
		"Resolve issues as DBA and deploy new oracle databases over linux",
		"This work sucks, I take the job just for see how development teams works inside of military organization",
		NULL
	}
};

job_t vr = {
	.company  = "vrweb",
	.location = "Santiago, CL",
	.title    = "Full stack Web developer",
	.started  = 1172707200,
	.left     = 1175212800,
	.description = {
		"Web development in perl with in-house PERL frameworks",
		"In simple words, they have a big ego and the job no big deal. I was fired",
		NULL
	}
};
job_t traza = {
	.company  = "Traza Ltda.",
	.location = "Santiago, CL",
	.title    = "Full stack developer",
	.started  = 1114898400,
	.left     = 1177970400,
	.description = {
		"Develop file format converter application in C",
		"Develop PHP web platform for document management",
		"The project ends and I was fired",
		NULL
	}
};

job_t ns = {
	.company  = "Netsecure Ltda.",
	.location = "Santiago, CL",
	.title    = "Networking and Security Consulting",
	.started  = 1049155200,
	.left     = 1077926400,
	.description = {
		"Security engineer in opensource platforms and networking appliances",
		"Early times, I was excited about security, the result is an expedition failed",
		"No programming at all and bored me",
		NULL
	}
};

/* Projects */
project_t mdbuilder = {
	.project = "mdbuilder",
	.url     = "http://github.com/mnothic/mdbuilder",
	.title   = "Developer",
	.started = 1306886400,
	.left    = 1309516143,
	.description = {
		"Daemon in C to automate postfix smtp user manage in a database model, great expedition",
		"Automate build and delete folders structure for postfix+dovecot",
		NULL
	}
};

project_t growpy = {
	.project = "growpy",
	.url     = "http://engine.cl/django-growpy/",
	.title   = "Lead",
	.started = 1295049600,
	.left    = CURRENT,
	.description = {
		"Python PoC filesystem stats collector",
		"Advanced administration WEB GUI. Use frameworks",
		"and dependencies like SQLAlchemy, Django, JSON and Jquery",
		NULL
	}
};

/* Alma matér */
school_t * schools[] = {
	&ipla,
	NULL
};

/* profesional experience stack */
job_t * jobs[] = {
	&amaris,
	&hp,
	&eyc,
	&adem,
	&fach,
	&vr,
	&traza,
	&ns,
	NULL
};

/* github proyects */
project_t * projects[] = {
	&growpy,
	&mdbuilder,
	NULL
};

void print_thing(thing_t * thing) {
	char started[100];
	char left[100];
	struct tm * ti;

	printf("%s at %s - %s\n", thing->title, thing->company, thing->location);

	ti = localtime(&thing->started);
	strftime(started, 100, "%B %d, %Y", ti);

	if (thing->left == CURRENT)  {
		printf("%s to now\n", started);
	} else {
		ti = localtime(&thing->left);
		strftime(left,    100, "%B %d, %Y", ti);
		printf("%s to %s\n", started, left);
	}

	char ** desc = thing->description;
	while (*desc) {
		printf("- %s\n", *desc);
		desc++;
	}
}

int main(int argc, char ** argv) {

    printf("If you compiled this get full IT history about me...\n");
	printf("%s\n%s\n%s\n\n", name, email, address);

	puts("Education\n");
	school_t ** s = schools;
	while (*s) {
		print_thing(*s);
		puts("");
		s++;
	}

	puts("Employment History\n");
	job_t ** j = jobs;
	while (*j) {
		print_thing(*j);
		puts("");
		j++;
	}

	puts("Github Projects\n");
	project_t ** p = projects;
	while (*p) {
		print_thing(*p);
		puts("");
		p++;
	}

	return 0;
}
