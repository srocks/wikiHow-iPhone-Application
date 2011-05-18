// Copyright (c) 2009 wikihow.com and Keishi Hattori
// 
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
// 
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.

#import <Foundation/Foundation.h>
#import "sqlite3.h"
#import "WHArticle.h"


@interface WHArticlePreloadedCache : NSObject {
	sqlite3 *database;
	sqlite3_stmt *load_statement;
	sqlite3_stmt *search_statement;
	sqlite3_stmt *category_search_statement;
	sqlite3_stmt *hydrate_statement;
	sqlite3_stmt *listup_statement;
}

+ (WHArticlePreloadedCache *)sharedPreloadedCache;
-(void)finalizeStatements;
- (void)initializeDatabase;
- (WHArticle *)cachedArticleWithIdentifier:(NSString *)identifier;
- (NSArray *)preloadedArticles:(NSString *)category;
- (NSArray *)findArticlesWithQuery:(NSString *)query;
- (NSArray *)preloadedCategories;
- (NSArray *)findArticlesWithCategory:(NSString *)category;
- (void)cleanup;

// Internal method. Don't call.
- (void)hydrateArticle:(WHArticle *)article;

@end
