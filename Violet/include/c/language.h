/* 
 * File:   language.h
 * Author: Domi
 *
 * Created on 2. Mai 2017, 20:06
 */

#ifndef LANGUAGE_H
#define	LANGUAGE_H

#ifdef	__cplusplus
extern "C" {
#endif
    



	#ifdef VSCODE_INTELLISENSE
	#undef PSTRING
	#undef LANGDEP
	#define PSTRING(...) { __VA_ARGS__ }
	#else
	#define PSTRING(...) __VA_ARGS__
	#endif


	// Define language dependent macro
	#ifdef LANG_GER
		#define LANGDEP(ger,en) ger
	#elif LANG_EN
		#define LANGDEP(ger,en) en
	#endif





#ifdef	__cplusplus
}
#endif

#endif	/* LANGUAGE_H */

