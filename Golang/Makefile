GOCMD = go 
RUNCMD = run 
BUILDCMD = build 
SRCFILE = main.go
SRCDIR = cmd
TARGETFILE = StudyPlatform
TARGETDIR = target

all: 
	$(GOCMD) $(RUNCMD) $(SRCDIR)/$(SRCFILE)
build: 
	mkdir -p $(TARGETDIR)
	$(GOCMD) $(BUILDCMD) -o $(TARGETDIR)/$(TARGETFILE) $(SRCDIR)/$(SRCFILE)
run: 
	$(TARGETDIR)/$(TARGETFILE)
